def lcs_problem(str1,str2):
    m = len(str1)
    n = len(str2)
    
    lcs_matriz = [[0 for x in range(n+1)] for x in range(m+1)]
    
    for i in range(m+1):
        for j in range(n+1):
            if str1[i-1] == str2[j-1]:
                lcs_matriz[i][j] = lcs_matriz[i-1][j-1]+1
            elif i == 0 or j == 0:
                lcs_matriz[i][j] = 0
            else:
                lcs_matriz[i][j] = max(lcs_matriz[i-1][j], lcs_matriz[i][j-1])
    return lcs_matriz[m][n]

string1 = "ACADB"
string2 = "CBDA"
print ("La longitud de la subsecuencia es ", lcs_problem(string1, string2))