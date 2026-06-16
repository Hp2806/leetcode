N, M = map(int, input().split())
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))

si= 0
ni = 0
count = 0

while si < N and ni < M:
    if B[ni] <= 2 * A[si]:
        count += 1
        si += 1
        ni += 1
    else:
        si += 1

print(count)
