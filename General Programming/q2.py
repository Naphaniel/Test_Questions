# Time complexity O(N), Space complexity O(1) excluding output array
def find_common_values(nums_1, nums_2):
    if not nums_1 or not nums_2:
        return []

    common_values = []
    first, second = 0, 0

    while first < len(nums_1) and second < len(nums_2):
        num_1, num_2 = nums_1[first], nums_2[second]
        if first > 0 and num_1 == nums_1[first-1]:
            first += 1
            continue
        if second > 0 and num_2 == nums_2[second-1]:
            second += 1
            continue
        if num_1 == num_2:
            common_values.append(num_1)
            first += 1
            second += 1
        elif num_2 > num_1:
            first += 1
        else:
            second += 1
    return common_values


# Time complexity O(logN) where N is number of digits, Space complexity O(1)
def even_digits(n):
    while n > 0:
        digit = n % 10
        if digit % 2 != 0:
            return False
        n //= 10
    return True
