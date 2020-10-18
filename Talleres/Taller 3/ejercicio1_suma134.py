arr = [1,3,4]

def sumarFormas(n):
    if n == 0:
        return 1
    if n < 0:
        return 0
    count=0
    for j in range(0,len(arr)):
        count += sumarFormas(n-arr[j])
    return count

print(sumarFormas(7))