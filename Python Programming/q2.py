# Time complexity O(N^2), Space complexity O(N^2)
def n_list_creation(n):
    return [[x for x in range(1, j+1)] for j in range(1, n+1)]
