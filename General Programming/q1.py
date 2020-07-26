# Time complexity O(N), Space complexity O(1)
def even_fibonacci_sum(n):
    mem = [1, 1]
    even_sum = 0
    num_even = 0
    while True:
        current_fib = mem[0] + mem[1]
        if current_fib % 2 == 0:
            even_sum += current_fib
            num_even += 1
            if num_even == n:
                return even_sum
        mem[0], mem[1] = mem[1], current_fib
