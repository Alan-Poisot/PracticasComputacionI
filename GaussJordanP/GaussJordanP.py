# -*- coding: utf-8 -*-
"""GaussJordan.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1eJPiYl6bGhGVS3zRGeRBriMV4AxS6NHh
"""

def swap(m,n,x):
    y=x+1
    for i in range(y,n):
        if m[i][x]!=0:
            return True, i;
    return False, 0;

n=int(input("Número de ecuaciones: "))
mat=[]
for i in range(n):
    r=[]
    for j in range(n+1):
        print("Valor elemento [",i,"][",j,"]: ")
        x=int(input())
        r.append(x)
    mat.append(r)

#Gauss
i=0
p=True
while i<n:
    if mat[i][i]!=0:
        for j in range(i+1,n+1):
            mat[i][j]=mat[i][j]/mat[i][i]
        mat[i][i]=1
        for j in range(i+1,n):
            temp=mat[j][i]
            for k in range(i,n+1):
                mat[j][k]=mat[j][k]-mat[i][k]*temp
        i=i+1
    else:
        ex,ind=swap(mat,n,i)
        if ex==True:
            mat[i],mat[ind]=mat[ind],mat[i]
        else:
            print("El sistema no tiene solución")
            i=n
            p=False

#Gauss-Jordan

if(p):
    i=n-1
    while i>0:
        for j in range (0,i):
            mat[j][n]=mat[j][n]-mat[i][n]*mat[j][i]
            mat[j][i]=0
        i=i-1

    #print(mat)
    print("Solución:")
    for i in range (0,n):
        print("x"+str(i)+" = "+str(mat[i][n]))