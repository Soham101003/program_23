import openai
openai.api_key="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"

#Function to generate a promt
def gpt_clone_bot(promt):
    client= openai.Client() #client instance
    #Creating a dictionary of instances 

    response=openai.completions.create(
        model= "gpt-3.5-turbo",
        prompt=promt,
        max_tokens=150,
        n=1,
        stop=None,
        temperature=0.7,

        messages=[{"role","user","content"}]
    )
    return response.choices[0].text.strip()

if __name__=="__main__":
    while True:
        user_input=input("You: ")
        #User wants to exit the prompt
        if user_input.lower() in ["quit", "bye", "exit"]:
            break
        
        response=gpt_clone_bot(user_input)
        print("Bot : ", response)