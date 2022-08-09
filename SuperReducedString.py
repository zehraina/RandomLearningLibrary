def superReducedString(s):
    l=[None]
    for i in range(len(s)):
        if s==[]:
            l.append(s[i])
        elif l[len(l)-1]==s[i]:
            l.pop()
        else:
            l.append(s[i])
        
    res = []
    for val in l:
        if val != None :
            res.append(val)
    x="".join(res)
    if x=="":
        print("Empty String")
    else: 
        print(x)

if __name__ == '__main__':
    s = input()
    superReducedString(s)

  

   
