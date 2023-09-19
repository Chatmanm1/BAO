import openai
import os
import speech_recognition as sr
from gtts import gTTS



# Load your API key from an environment variable or secret management service
openai.api_key = os.getenv("OPENAI_API_KEY") #need to add key. 

# Initialize recognizer and microphone
recognizer = sr.Recognizer()
microphone = sr.Microphone()




def chatbot():
  # Create a list to store all the messages for context
  messages = [
    {"role": "system", "content": "You are a Starwars droid named Lola, you are helpful and provide the user with information they ask for it."},
  ]


while True:
    
        
  # Keep repeating the following
  while True:
    # Prompt user for input
    user_input = listen_to_user()
    message = input(user_input)

    # Exit program if user inputs "quit"
    if message.lower() == "quit":
      break

    # Add each new message to the list
    messages.append({"role": "user", "content": message})

    # Request gpt-3.5-turbo for chat completion
    response = openai.ChatCompletion.create(
      model="gpt-3.5-turbo",
      messages=messages
    )

    # Print the response and add it to the messages list    
    chat_message = response['choices'][0]['message']['content']
    print(f"Bot: {chat_message}")
    messages.append({"role": "assistant", "content": chat_message})
    respond(chat_message)




if __name__ == "__main__":
  print("Start chatting with the bot (type 'quit' to stop)!")
  chatbot()




def listen_to_user():
    with microphone as source:
        print("Listening...")
        audio = recognizer.listen(source)

    try:
        user_input = recognizer.recognize_google(audio)
        print(f"You said: {user_input}")
        return user_input
    except sr.UnknownValueError:
        print("Sorry, I couldn't understand what you said.")
        return None

def respond(text):
    tts = gTTS(text=text, lang='en')
    tts.save("response.mp3")
    os.system("mpg123 response.mp3")  # You may need to change this command based on your system

