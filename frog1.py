import sys
def solve():
    n = int(sys.stdin.readline())
    h = list(map(int, sys.stdin.readline().split()))    
    dp = [0] * n    
    dp[0] = 0
    if n > 1:
        dp[1] = abs(h[1] - h[0])        
    for i in range(2, n):
        opt1 = dp[i-1] + abs(h[i] - h[i-1])
        opt2 = dp[i-2] + abs(h[i] - h[i-2])        
        dp[i] = min(opt1, opt2)        
    print(dp[n-1])

solve()
