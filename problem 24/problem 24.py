def text_fitting(width, height, text):
    words = text.split()
    lines = 1
    current_width = 0
    current_height = 0

    for word in words:
        word_length = len(word)
        if current_width == 0:
            current_width += word_length
        else:
            current_width += word_length + 1  # accounting for the space
        if current_width <= width:
            continue
        else:
            lines += 1
            current_width = word_length

        if lines > height:
            break

    return lines

# Reading input
width = 2 #int(input())
height = 6 #int(input())
text = "COSC 3320" #input()

# Calling the function and printing the result
print(text_fitting(width, height, text))
