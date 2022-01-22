# -*- coding: utf-8 -*-
"""
Created on Sun Jan  9 17:58:04 2022

@author: georg
"""

import numpy as np

#write matrix here

Mat = np.mat([[1,2,3,4,5],[3,4,2,1,5],[4,2,5,1,3],[2,3,5,1,4],[5,4,1,3,2]])

Mat_T = Mat.T

ordered = sorted(Mat_T.tolist(), key = sum)
o = sorted(Mat_T.tolist(), key = sum)
n = len(ordered)

from itertools import islice

def nth_index(iterable, value, n):
    matches = (idx for idx, val in enumerate(iterable) if val == value)
    return next(islice(matches, n-1, n), None)

def max_score(M, pairs = [], chosen_students = []):
    #input: list of lists representing the columns of the starting matrix ordered by the column sum
    #output: the maximum satisfaction score
    if len(M) == 0:
        return 0, pairs, chosen_students
    elif len(M) == 1:
        return M, pairs, chosen_students
    elif len(M) == 2:
        proj1 = n-2
        proj2 = n-1
        if M[0][0] + M[1][1] >= M[0][1] + M[1][0]:
            stud1 = o[proj1].index(M[0][0])
            if stud1 not in chosen_students:
                chosen_students.append(stud1)
            else:
                k = 1
                while(stud1 in chosen_students):
                    stud1 = nth_index(o[proj1], M[0][0], k )
                    k+=1
                chosen_students.append(stud1)
                pairs.append((stud1,proj1))
            stud2 = o[proj2].index(M[1][1])
            if stud2 not in chosen_students:
                chosen_students.append(stud2)
            else:
                k = 1
                while(stud2 in chosen_students):
                    stud2 = nth_index(o[proj2], M[1][1], k )
                    k+=1
                chosen_students.append(stud2)
                pairs.append((stud2,proj2))
        else:
            stud1 = o[proj1].index(M[0][1])
            if stud1 not in chosen_students:
                chosen_students.append(stud1)
            else:
                k = 1
                while(stud1 in chosen_students):
                    stud1 = nth_index(o[proj1], M[0][1], k )
                    k+=1
                chosen_students.append(stud1)
                pairs.append((stud1,proj1))
            stud2 = o[proj2].index(M[1][0])
            if stud2 not in chosen_students:
                chosen_students.append(stud2)
            else:
                k = 1
                while(stud2 in chosen_students):
                    stud2 = nth_index(o[proj2], M[1][0], k )
                    k+=1
                chosen_students.append(stud2)
                pairs.append((stud2,proj2))
            
        pairs.append((stud1,proj1))
        pairs.append((stud2,proj2))
        
        
        return max(M[0][0] + M[1][1], M[0][1] + M[1][0] ), pairs
    
    else:
        m = max(M[0])
        idx = M[0].index(m)
        proj = n - len(M) 
        stud = o[proj].index(m)  ## pas en o(transpose) mais il faut chercher dans l'original
        if stud not in chosen_students:
            chosen_students.append(stud)
        else:
            k = 1
            while(stud in chosen_students):
                stud = nth_index(o[proj], m, k )
                k+=1
            chosen_students.append(stud)
        
        
        
        pairs.append((stud,proj))
        for line in M[1:len(M)]:
            line.pop(idx)
        new_mat = M[1:len(M)]
       # print(new_mat)
        #print( m, idx)
        #pairs.append((m,idx))
        return m + max_score(new_mat)[0] , pairs, chosen_students




sc, p, chosen= max_score(ordered)
#print(sc,p)

#print("On a les pairs: ", max_score(ordered), "qui donne le score maximum: ", sc, "pour la matrice de choice: \n",
     # np.mat(0).T)
     
print('On a les pairs (etudiant, projet): \n ', p, '\n qui donne le score \n ', sc, '\n pour la matrice (lignes -> etudiants, colonnes -> projets) \n' , np.mat(o).T)


    
    

    
    

    
    

    