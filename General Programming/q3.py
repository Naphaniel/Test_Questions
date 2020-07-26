# Time complexity O(logN) where N is number of digits, Space complexity O(1)
def even_digits(n):
    while n > 0:
        digit = n % 10
        if digit % 2 != 0:
            return False
        n //= 10
    return True
