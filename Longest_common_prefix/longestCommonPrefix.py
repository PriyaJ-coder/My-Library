import sys
import functools

def cmp(a, b):
    return 1 if a > b else 0 if a == b else -1

def longestCommonPrefix():
    keyfunc = functools.cmp_to_key(lambda x, y: cmp(len(x), len(y)))
    strs.sort(key=keyfunc)
    # print(strs)

    temp = str(strs[0])
    if (len(temp) == 0):
        z = ""
        return z
    if (len(strs) == 1):
        return temp

    res = ''
    flag = 0
    for i in range(0, len(temp)):
        # print(temp[i])
        for element in range(1, len(strs)):
            var = str(strs[element])
            # print(var)
            # print(var[i])
            if (temp[i] != var[i]):
                flag = 1
                # print("BREAK")
                break
        if (flag == 1):
            # sys.stdout.write("")
            if (len(res) == 0):
                x = ""
                return x
            return res
        else:
            res = res + temp[i]
            # sys.stdout.write(temp[i])
    return res


strs = list(map(str, sys.stdin.readline().split()))
print(longestCommonPrefix())

# INPUT--> flower flow flaunt flop flip flee 