    mov cx, N 
    jmp bottom
top:
    BODY ; print something
    dec cx
bottom:
    cmp cx, 0
    jne top