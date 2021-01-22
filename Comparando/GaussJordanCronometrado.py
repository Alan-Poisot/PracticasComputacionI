# -*- coding: utf-8 -*-

#Gauss-Jordan
import time
import numpy as np
import random as rn

def swap(m,n,x):
    y=x+1
    for i in range(y,n):
        if m[i][x]!=0:
            return True, i;
    return False, 0;

n=int(input("Número de ecuaciones: "))
mat=np.zeros((n,n+1))
r=np.zeros((n+1))
for i in range(n):

    for j in range(n+1):
        r[j]=rn.randrange(-100,100)
    mat[i]=r


w=time.monotonic()
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
print((time.monotonic()-w)*1000," ms")


#Gauss-Jordan Numpy
mt=np.zeros((n,n+1))
for i in range (0,n):
    mt[i]=mat[i]

z=time.monotonic()
#Gauss
i=0
p=True
while i<n:
    if mt[i][i]!=0:
        for j in range(i+1,n+1):
            mt[i][j]=mt[i][j]/mt[i][i]
        mt[i][i]=1
        for j in range(i+1,n):
            temp=mt[j][i]
            for k in range(i,n+1):
                mt[j][k]=mt[j][k]-mt[i][k]*temp
        i=i+1
    else:
        ex,ind=swap(mt,n,i)
        if ex==True:
            mt[i],mt[ind]=mt[ind],mt[i]
        else:
            print("El sistema no tiene solución")
            i=n
            p=False

#Gauss-Jordan

if(p):
    i=n-1
    while i>0:
        for j in range (0,i):
            mt[j][n]=mt[j][n]-mt[i][n]*mt[j][i]
            mt[j][i]=0
        i=i-1

    #print(mt)
print((time.monotonic()-z)*1000," ms")