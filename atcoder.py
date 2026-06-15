import math
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return abs(a)
T = int(input())
for _ in range(T):
    line = input().split()
    N = int(line[0])
    A = int(line[1])
    B = int(line[2])
    C = int(line[3])
    D = int(line[4])
    result = 0
    for i in range(1, N + 1):
        result = (result + gcd(A * i + B, C * i + D)) 
    print(result)
