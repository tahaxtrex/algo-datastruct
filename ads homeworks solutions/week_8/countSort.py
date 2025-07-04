array = [9, 1, 6, 7, 6, 2, 1]  

def counting_sort(array):
    k = max(array)
    n = len(array)
    output = [0] * n
    temp = [0] * (k + 1)

    for i in range(n):
        temp[array[i]] += 1
    for i in range(1, k + 1):
        temp[i] += temp[i - 1]
    for i in range(n - 1, -1, -1):
        output[temp[array[i]] - 1] = array[i]
        temp[array[i]] -= 1
    return output

print(*counting_sort(array))

