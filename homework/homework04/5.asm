    JMP start
counter: 0
limit: 256
start:
    Load [counter]
    Write 0x8
    Add 1
    Store [counter]
    Sub [limit]
    JLZ start
end:
    JMP end
