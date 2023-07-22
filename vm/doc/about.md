# about my ir language

## instruction
```asm
register :
    sp
    bp
    ax
    bx
    cx
    dx
    
stack :

heap:

instruction:



basic: -> is must

    mov 
    push
    pop
    add
    cmp
    leave
    goto
    larg
    ret
    
    
    int
    float
    char
    
```


## demo
```asm

add(int,int)->int ；（自动根据参数数量开辟stack)
    larg ax,0 ;0 the first arg ->load from stack
    larg bx,1 ;1 the second arg 
    add ax,bx
    ret       ; ret  
```


