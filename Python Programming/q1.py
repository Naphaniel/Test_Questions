# Time complexity O(N), Space complexity O(1)
def sum_of_divisible(n, k):
    return sum(x for x in range(1, n + 1) if x % k == 0)
