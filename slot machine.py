import random

credit = 1
fruit = ['Cherry','Bell','Lemon','Orange','Star','Skull']

def roll():
    global credit
    credit=credit-0.2
    results = []
    bell_num = 0
    skull_num = 0
    same_num = 0

    for i in range(3):
        m = random.randint(0,5)
        k = fruit[m]
        results.append(k)
        if results[i]=="Bell":
            bell_num+=1
        if results[i]=="Skull":
            skull_num+=1

    print("Results:",end="")

    for i in results:
        print(i,end="  ")
        
    print()

    if results[0]==results[1]:
        same_num+=1
    if results[0]==results[2]:
        same_num+=1
    if results[2]==results[1]:
        same_num+=1

    if skull_num>=2:
        if skull_num==3:
            credit=0;
        elif skull_num==2:
            credit-=1
    elif bell_num==3:
        credit+=5
    elif same_num==3:
        credit+=1
    elif same_num==2:
        credit=credit+0.5

        
if credit<0:
    credit=0
while credit>=0.2:
    print("You have ",round(credit,1)," credits")
    print("Would you like to continue or quiz?")
    q=input()
    if q=="quiz":
        break
    roll()

print("In the end, you have ",credit," credits")
    


    
        
    
