# Data Structure Homework 3

**Student ID : 41247001S**

### Question 1 (a)

![](img1.png)

### Question 1(b)

![](img2.png)

Answer derived from the below path.

![](img3.png)

### Question 2(a)

![](img4.png)

### Question 2(b)

![](img5.png)

![](img6.png)


### Question 3

![](img7.png)

### Question 4

![](img8.png)

```python
# pseudo postfix eval code 
# this is based on code in homework 3
postfix:
    while(token != endOfString):
        if(token.isdigit()) stack.push(int(token))
        else:
            number2 = stack.pop()
            number1 = stack.pop()
            stack.push(calculate(number1 , token , number2))
        token = get_token_fromString()
    return stack.top()

# modify to prefix version
prefix:
    while(token != endOfString):
        if(token.isdigit()):
            if(stack.top().isdigit()):
                number2 = int(token)
                number1 = stack.pop()
                calc = stack.pop() # +-*/
                stack.push(calculate(number1 , calc , number2))
            else:
                stack.push(int(token))
        else:
            stack.push(token)
        token = get_token_fromString()
    return stack.top()

```