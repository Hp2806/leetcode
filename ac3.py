T = int(input())

for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))

    l, r = 0, n - 1
    mn = 10**18
    mx = -1
    ans = 0

    while l <= r:
        moved = False

        for x, side in [(a[l], 0), (a[r], 1)]:
            if ans == 0 or x < mn or x > mx:
                if side == 0:
                    l += 1
                else:
                    r -= 1

                if ans == 0:
                    mn = mx = x
                else:
                    mn = min(mn, x)
                    mx = max(mx, x)

                ans += 1
                moved = True
                break

        if not moved:
            break

    print(ans)
