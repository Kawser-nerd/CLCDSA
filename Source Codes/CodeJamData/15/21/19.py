# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""

# prend un entier et le retourne en effaçant les zéros devant

def swap(k):
    return int(str(k)[::-1])


def cut(n):
    a=str(n)
    b=len(a)
    c=a[b//2:]
    return int(c)

def solution(n):
    compteur=1
    while n>10:
        
        
        if cut(n)==0: # on perd une décimale
            n=n-1
            compteur=compteur+1
#            print compteur
        a=cut(n)
        if cut(n)>1:
            n=n-cut(n)+1
            compteur=compteur+a-1
#            print compteur
        a=swap(n)
        if a!=n: # on swap
            n=a
            compteur=compteur+1
#            print compteur
        else: # on est dans le cas 1000000001
            n=n-2
            compteur=compteur+2
#            print compteur
    return compteur+8
            
    
        
    
    
    
#def generation(N):
#    L=[0,1] # on met le 0 pour que cela ne merde pas avec le comptage
#    n=1
#    for k in range(2,N+1):
#        
#        if str(k)[-1]!='0': # si le dernier caractère est un 0, on ne peut pas l'avoir avec un swap
#            a=swap(k)
#            #print a
#            # on regarde si le nombre swappé est plus petit que la taille de la liste
#            if a<n: # autrement dit le nombre est un nombre déjà atteint, on suppose que l'on n'a pas intérêt
#                    # à remonter au dessus d'un nombre puis de redescendre (vrai ?)
#                    # cela signifie que l'on arrive à swap(k) en a coups
#                
#                if L[a]<L[k-1]+1:
#                    L=L+[L[a]+1]
#                else:
#                    L=L+[L[k-1]+1]
#            else: # swapper ne sert à rien
#                L=L+[L[k-1]+1]
#        else:
#            L=L+[L[k-1]+1]
#        n=n+1
#    return L
            
        



import numpy as np

def main(ifn='A-large.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            
                  
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
            
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                
                # on commence par lire le nombre de tribus
                i=int(inf.readline().strip())    # convertit en liste une ligne en virant les espaces
                
                if i<19:
                    n=i
                else:
                    n=solution(i)

                



                    
                ouf.write("%d\n" %n)   # recopie le nombre puis saute une ligne                    


       


