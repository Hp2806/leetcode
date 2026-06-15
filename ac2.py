N, MOD = map(int, input().split())

# Stirling numbers of the second kind
S = [[0] * (N + 1) for _ in range(N + 1)]
# Binomial coefficients
C = [[0] * (N + 1) for _ in range(N + 1)]

for n in range(N + 1):
    S[n][n] = 1
    C[n][0] = 1

    if n:
        S[n][1] = 1

    for k in range(2, n):
        S[n][k] = (S[n - 1][k - 1] + k * S[n - 1][k]) % MOD

    for k in range(1, n + 1):
        C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD

pow2 = [1] * (N * N + 1)
for i in range(1, N * N + 1):
    pow2[i] = (pow2[i - 1] * 2) % MOD

cnt = [0] * (N + 1)
cnt[0] = 1

ans = 1

for n in range(1, N + 1):
    for s in range(1, n + 1):
        tmp = 0
        sign = 1

        for a in range(1, s + 1):
            tmp += sign * S[s][a] * pow2[a * (n - s)]
            tmp %= MOD
            sign = -sign

        cnt[n] += C[n][s] * cnt[n - s] % MOD * tmp
        cnt[n] %= MOD

    ans += C[N][n] * cnt[n]
    ans %= MOD

print(ans)
