def buildList(A, n):
    for r in range(n):
        A[r] = r + 1
    return runSimulation1(A, n, k)


def candle(n, k):
    A = [n]
    buildList(A, n)
    return


def runSimulation1(A, n, k):
    r = 0
    while n > 1:
        i = 0
        while i < k:
            r = (r + 1) % n
            if A[r] != 0:
                i += 1
        A[r] = 0
        n = n - 1
        while A[r] == 0:
            r = (r + 1) % n
    return A[r]


def runSimulation2(A, n, k):
    r = 0
    while n > 1:
        r = (r + k) % n
        remove(r)
    return A[0]


A = [7]
runSimulation1(A, 7, 3)
