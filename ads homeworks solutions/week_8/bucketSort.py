def bucketSort(array):
    n = len(array)
    if n == 0:
        return array
    buckets = [[] for _ in range(10)]
    for each in array:
        index = int(each*10) 
        buckets[index].append(each)
    for bucket in buckets:
        bucket.sort()
    sorted = []
    for bucket in buckets:
        sorted.extend(bucket)
    
    return sorted

mylist = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]

print(bucketSort(mylist))