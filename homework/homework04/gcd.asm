    JMP start
num1: 0
num2: 0
remainder: 0
start:
    Read 256
    Store [num1]
    Read 256
    Store [num2]
loop:
    Load [num2]
    JZ done
    Load [num1]
    Mod [num2]
    Store [remainder]
    Load [num2]
    Store [num1]
    Load [remainder]
    Store [num2]
    JMP loop
done:
    Load [num1]
    Write 512
end:
    JMP end