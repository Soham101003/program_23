import openai

openai.api_key = "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"

# Function to generate a response
def gpt_clone_bot(prompt):
    client = openai.Client(api_key= "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" )  # Create a client instance
    response = client.completions.create(
        model="gpt-3.5-turbo",  # Updated model name
        prompt=prompt,
        max_tokens=150,  # Optional parameter to control response length
        n=1,  # Optional parameter to specify number of completions
        stop=None,  # Optional parameter to stop at specific tokens
        temperature=0.7,  # Optional parameter for creativity
    )
    return response.choices[0].text.strip()  # Access the generated text

if __name__ == "__main__":
    while True:
        user_input = input("You: ")
        if user_input.lower() in ["quit", "bye", "exit"]:
            break
        response = gpt_clone_bot(user_input)
        print("Bot : ", response)
