def calculate_navigable_airspace(heights):
    if not heights: return 0
    n = len(heights)
    left_max = [0] * n
    curr_max = 0
    for i in range(n):
        left_max[i] = curr_max = max(curr_max, heights[i])
    total_airspace = 0
    right_max = 0
    for i in range(n - 1, -1, -1):
        right_max = max(right_max, heights[i])
        total_airspace += min(left_max[i], right_max) - heights[i]
    return total_airspace
buildings = [0,1,0,2,1,0,1,3,2,1,2,1]
print("Total Navigable Airspace =", calculate_navigable_airspace(buildings))
