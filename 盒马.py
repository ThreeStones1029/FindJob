def fn(n):
    return 1 if n < 2 else n * fn(n - 1)

print(list(map(fn, filter(lambda n: n % 3, range(6)))))