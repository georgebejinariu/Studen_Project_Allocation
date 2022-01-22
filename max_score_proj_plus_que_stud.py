# -*- coding: utf-8 -*-
"""
Created on Sun Jan  9 17:58:04 2022

@author: georg
"""

import numpy as np

#write matrix here

Mat = np.mat([[1,2,3,4,5],[3,4,2,1,5],[4,2,5,1,3],[2,3,5,1,4],[5,4,1,3,2]])


#Mat = np.mat([[1,2,3,1,4,5,7],[3,4,2,7,6,1,5],[4,2,5,1,6,7,3],[2,3,5,6,1,7,4],[5,4,6,1,3,2,7]])

Mat_T = Mat.T

ordered = sorted(Mat_T.tolist(), key = sum)
o = sorted(Mat_T.tolist(), key = sum)
op= sorted(Mat_T.tolist(), key = sum)

n = len(ordered)  ### number of projects
d = len(ordered) - len(ordered[0]) ## nr_proj - nr_students

from itertools import islice

def nth_index(iterable, value, n):
    matches = (idx for idx, val in enumerate(iterable) if val == value)
    return next(islice(matches, n-1, n), None)

def max_score(M, pairs = [], chosen_students = []):
    #input: list of lists representing the columns of the starting matrix ordered by the column sum
    #output: the maximum satisfaction score
    if len(M) == 0:
        print("ce pula mea e d = ", d)
        return 0, pairs, chosen_students
    elif len(M) == d:
    
        return 0, pairs
    

    else:
        m = -1
        for j in range(d+1):
            m_pot = max(M[j])
            idx_pot = M[j].index(m_pot)
            proj_pot = n - len(M) + j
            
            if m_pot >= m:
                m = m_pot
                idx = idx_pot
                proj = proj_pot
            
            
        
        #m = max(M[d])
        #idx = M[d].index(m)
        #proj = n - len(M) +d
        
        
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
        
        #print(new_mat)
        #print( pairs)
        #pairs.append((m,idx))
        
        return m + max_score(new_mat)[0] , pairs




sc, p= max_score(ordered)
#print(sc,p)

#print("On a les pairs: ", max_score(ordered), "qui donne le score maximum: ", sc, "pour la matrice de choice: \n",
     # np.mat(0).T)
     
print('On a les pairs (etudiant, projet): \n ', p, '\n qui donne le score \n ', sc, '\n pour la matrice (lignes -> etudiants, colonnes -> projets) \n' , np.mat(o).T)


    
    

    
    

    
    

    