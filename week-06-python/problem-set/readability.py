def main():
    sentence = input("Text: ")

    # Number of letters, words, and sentences in the string
    letters = count_letters(sentence)
    words = count_words(sentence)
    sentences = count_sentences(sentence)

    # Check to avoid division by zero
    if words == 0:
        print("No words to analyze.")
        return

    # Average number of letters and sentences per 100 words
    avg_letters = (100 * letters) / words
    avg_sentences = (100 * sentences) / words

    # Coleman-Liau index
    index = calculate_index(avg_letters, avg_sentences)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

def count_letters(sentence):
    # Counts and returns the number of letters in a string.
    return sum(1 for character in sentence if character.isalpha())

def count_words(sentence):
    # Counts and returns the number of words in a string.
    return len(sentence.split())

def count_sentences(sentence):
    # Counts and returns the number of sentences in a string.
    return sum(1 for character in sentence if character in ".!?")

def calculate_index(avg_letters, avg_sentences):
    # Calculates the approximate grade level needed to comprehend some text according to the Coleman-Liau formula.
    return round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)

if __name__ == "__main__":
    main()
