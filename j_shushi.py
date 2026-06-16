import sys
def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    c1 = a.count(1)
    c2 = a.count(2)
    c3 = a.count(3)
    dp = [[[0.0] * (n + 1) for _ in range(n + 1)] for _ in range(n + 1)]
    for i in range(n + 1): 
        for j in range(n + 1 - i): 
            for k in range(n + 1 - i - j): 
                if i == 0 and j == 0 and k == 0:
                    continue
                sushi_dishes = i + j + k
                res = n
                if i > 0:
                    res += i * dp[i-1][j+1][k]
                if j > 0:
                    res += j * dp[i][j-1][k+1]
                if k > 0:
                    res += k * dp[i][j][k-1]
                
                dp[i][j][k] = res / sushi_dishes
    print(f"{dp[c3][c2][c1]:.15f}")
if __name__ == "__main__":
    solve()
