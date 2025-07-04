def counting_sort(words, pos):
    n = len(words)
    output = ["" for _ in range(n)]
    count = [0] * 256  # ASCII range

    for word in words:
        char = ord(word[pos])
        count[char] += 1

    for i in range(1, 256):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        char = ord(words[i][pos])
        count[char] -= 1
        output[count[char]] = words[i]

    return output


def wordSort(words):
    n = len(words)
    k = max(len(word) for word in words)
    array = [word.ljust(k, ' ') for word in words]

    for pos in reversed(range(k)):
        array = counting_sort(array, pos)

    return [word.strip() for word in array]


words = ["word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"]
sorted_words = wordSort(words)
print(sorted_words)


