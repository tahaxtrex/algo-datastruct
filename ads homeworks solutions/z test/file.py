import sys

def parse_instruction(instr):
    instr = instr.strip()
    if ':' in instr:
        label, rest = instr.split(':', 1)
        instr = rest.strip()
        if not instr:
            return None, [], False, False

    parts = instr.split(maxsplit=1)
    if len(parts) < 2:
        return None, [], False, False

    opcode = parts[0]
    operands = parts[1]
    operand_list = [op.strip() for op in operands.split(',')]

    # R-type
    if opcode in ['add', 'sub', 'and', 'or', 'slt']:
        if len(operand_list) == 3:
            rd, rs, rt = operand_list
            return rd.strip('$'), [rs.strip('$'), rt.strip('$')], False, False
        return None, [], False, False

    # I-type arithmetic
    elif opcode in ['addi', 'andi', 'ori']:
        if len(operand_list) == 3:
            rt, rs, imm = operand_list
            return rt.strip('$'), [rs.strip('$')], False, False
        return None, [], False, False

    # Load
    elif opcode == 'lw':
        if len(operand_list) == 2:
            rt = operand_list[0].strip('$')
            mem_part = operand_list[1]
            try:
                offset, base = mem_part.split('(')
                base = base.strip(')$')
                return rt, [base], False, True
            except ValueError:
                return None, [], False, False
        return None, [], False, False

    # Store
    elif opcode == 'sw':
        if len(operand_list) == 2:
            rt = operand_list[0].strip('$')
            mem_part = operand_list[1]
            try:
                offset, base = mem_part.split('(')
                base = base.strip(')$')
                return None, [rt, base], False, False
            except ValueError:
                return None, [], False, False
        return None, [], False, False

    # Branches
    elif opcode in ['beq', 'bne']:
        if len(operand_list) == 3:
            rs, rt, label = operand_list
            return None, [rs.strip('$'), rt.strip('$')], True, False
        return None, [], False, False

    # Jump
    elif opcode == 'j':
        return None, [], True, False

    return None, [], False, False


# Read instructions from standard input
instructions = [line.strip() for line in sys.stdin.readlines() if line.strip()]
parsed = [parse_instruction(instr) for instr in instructions]

# Analyze and report hazards
for i in range(len(instructions)):
    cycle = i + 1
    write_prev, _, _, _ = parsed[i-1] if i > 0 else (None, [], False, False)
    write_prev2, _, _, load2 = parsed[i-2] if i > 1 else (None, [], False, False)
    _, reads, is_branch, _ = parsed[i]

    # Control hazard
    if is_branch:
        print(f"Cycle {cycle}: Control hazard - stall")
        continue

    # RAW hazard from immediately previous instruction
    if write_prev and write_prev in reads:
        print(f"Cycle {cycle}: RAW hazard on ${write_prev} - forwarding")
        continue

    # RAW hazard from two-back instruction if it's not a load
    if write_prev2 and not load2 and write_prev2 in reads:
        print(f"Cycle {cycle}: RAW hazard on ${write_prev2} - forwarding")
        continue
