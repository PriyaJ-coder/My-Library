# Using heap algorithm, time commplexity will be O(n!)
def permutations(string):
    n = len(string)
    a = list(string)
    c = [0] * n

    result = [string]

    i = 0
    while i < n:
        if c[i] < i:
            if i % 2 == 0:
                a[0], a[i] = a[i], a[0]
            else:
                a[c[i]], a[i] = a[i], a[c[i]]

            result.append("".join(a))
            c[i] += 1
            i = 0
        else:
            c[i] = 0
            i += 1

    return result


result = permutations("cca")
print(result)
