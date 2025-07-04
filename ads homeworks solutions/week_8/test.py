array = [945, 132, 61, 7, 633, 211, 179, 331, 136, 798, 698, 2]  

def lsd_radixsort(array, digit_place):
    n = len(array)
    output = [0] * n
    count = [0] * 10


    for i in range(n):
        digit = (array[i] // digit_place) % 10
        count[digit] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        digit = (array[i] // digit_place) % 10
        count[digit] -= 1
        output[count[digit]] = array[i]

    return output

def radix_sort(array):
    max_num = max(array)
    digit_place = 1
    while max_num // digit_place > 0:
        array = lsd_radixsort(array, digit_place)
        digit_place *= 10
    return array

print(*radix_sort(array))
