def get_digit(num, digit_place):
    return (num // digit_place) % 10


def msd_radix_sort(array, digit_place):
    if len(array) <= 1 or digit_place == 0:
        return array

    buckets = [[] for _ in range(10)]

    for num in array:
        digit = get_digit(num, digit_place)
        buckets[digit].append(num)


    result = []
    for bucket in buckets:
        sorted_bucket = msd_radix_sort(bucket, digit_place // 10)
        result.extend(sorted_bucket)

    return result


def radix_sort_msd(array):
    if not array:
        return []

    max_num = max(array)
    digit_place = 1
    while max_num >= 10:
        max_num //= 10
        digit_place *= 10

    return msd_radix_sort(array, digit_place)

array = [945, 132, 61, 7, 633, 211, 179, 331, 136, 798, 698, 2] 

print(radix_sort_msd(array))