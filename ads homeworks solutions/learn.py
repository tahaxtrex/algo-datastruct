import turtle
import time
import random

# Screen setup
screen = turtle.Screen()
screen.title("Snake Game")
screen.bgcolor("black")
screen.setup(width=600, height=600)
screen.tracer(0)  # Turns off auto updates

# Snake setup
snake = []
for i in range(3):  # Initial snake length
    segment = turtle.Turtle("square")
    segment.color("white")
    segment.penup()
    segment.goto(-20 * i, 0)  # Position segments in a row
    snake.append(segment)

# Food setup
food = turtle.Turtle("circle")
food.color("red")
food.penup()
food.goto(random.randint(-290, 290), random.randint(-290, 290))

# Movement controls
direction = "stop"

def move():
    if direction != "stop":
        for i in range(len(snake) - 1, 0, -1):
            snake[i].goto(snake[i - 1].pos())  # Move segments
        
        if direction == "up":
            snake[0].sety(snake[0].ycor() + 20)
        elif direction == "down":
            snake[0].sety(snake[0].ycor() - 20)
        elif direction == "left":
            snake[0].setx(snake[0].xcor() - 20)
        elif direction == "right":
            snake[0].setx(snake[0].xcor() + 20)

# Key bindings
def go_up():
    global direction
    if direction != "down":
        direction = "up"

def go_down():
    global direction
    if direction != "up":
        direction = "down"

def go_left():
    global direction
    if direction != "right":
        direction = "left"

def go_right():
    global direction
    if direction != "left":
        direction = "right"

screen.listen()
screen.onkey(go_up, "Up")
screen.onkey(go_down, "Down")
screen.onkey(go_left, "Left")
screen.onkey(go_right, "Right")

# Main game loop
while True:
    screen.update()
    move()
    time.sleep(0.1)

    # Check for collision with food
    if snake[0].distance(food) < 15:
        food.goto(random.randint(-290, 290), random.randint(-290, 290))
        
        # Add a new segment
        segment = turtle.Turtle("square")
        segment.color("white")
        segment.penup()
        snake.append(segment)

screen.mainloop()