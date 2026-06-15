def kadane(arr):
    max_so_far = -float('inf')
    current_max = 0
    for x in arr:
        current_max += x
        if max_so_far < current_max:
            max_so_far = current_max
        if current_max < 0:
            current_max = 0
    return max_so_far
def maximum_sum_submatrix():
    R = int(input("Enter number of rows (R): "))
    C = int(input("Enter number of columns (C): "))
    M = []
    print(f"Enter the matrix row values:")
    for i in range(R):
        row = list(map(int, input().split()))
        M.append(row)
    max_total = -float('inf')
    for top in range(R):
        column_sums = [0] * C
        for bottom in range(top, R):
            for col in range(C):
                column_sums[col] += M[bottom][col]
            current_max = kadane(column_sums)
            if current_max > max_total:
                max_total = current_max
    print("Maximum Sum:", max_total)
if __name__ == "__main__":
    maximum_sum_submatrix()
