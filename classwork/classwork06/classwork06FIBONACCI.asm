    JMP start
num1: 0
num2: 1
sum: 0
limit: 10
count: 0
start: 
    Load [sum]
    Add [num1]
    Write 255
    Add [num2]
    Store [sum]
    Load [num2]
    Store [num1]
    Load [sum]
    Store [num2]
    Load [count]
    Add 1
    Store [count]
    Sub [limit]
    JLZ start
end: JMP end
    
