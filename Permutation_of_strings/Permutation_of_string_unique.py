# the algorithm known as "Steinhaus-Johnson-Trotter algorithm with Even's speedup", generates all permutations of a sequence in lexicographic order, without generating duplicates

total = 0

def swap(arr, i, j):
	temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp
	return arr

def permute(i, s):
	global total
	if(i == (len(s) - 1)):
		print(s)
		total += 1
		return
	
	prev = '*'
	for j in range(i,len(s)):
		temp = list(s)
		if (j > i and temp[i] == temp[j]):
			continue
		if (prev != '*' and prev == s[j]):
			continue
		temp = swap(temp,i,j)
		prev = s[j]
		permute(i + 1, "".join(temp))

def sortString(inputString):
	tempArray = list(inputString)
	tempArray.sort()
	return "".join(tempArray)
s = "all"
s = sortString(s)
permute(0, s)
print(f"Total distinct permutations = {total}")
