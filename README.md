
# Ask-Me-System
## what's Ask Me ?
* it is a simulation to [ask.fm](https://ask.fm/) app.

# waht i have done ? 
* I First Draw an initial uml Diagram for the project
* I have created Projects classes with no implementation
* Then I Implemented a features in source files
* For Database:
    * I have no experience, so I used a simple trick
    * So I Created Function that read and write on files
    * I used this function every time I need to update the UI
* I created a utility file which has repeated tasks and used it everywhere else
---

# how to Set Up
* Clone the Project
* Open the project as cmake Project either on vs code or clion
* Use Data Below as test data
* Enjoy ...

# Use below data to test.

# initial user data
| Id | UserName | Password |       Name           |     Email         | Allow Anynomous |
|----:| --------:| --------:| --------------------:|------------------:|---------------:|
| 13 | mostafa  | 111      | mostafa_saad_ibrahim | mostafa@gmail.com |  1              |
| 11 | noha     | 222      | noha_salah           | nono171@gmail.com |  0              |
| 45 | ali      | 333      | ali_wael             | wael@gmail.com    |  0              |
---

#### Initial Question data, to answer questions

| Question Id | Parent Id | From User Id | To User Id | Is Anynomous? | Text | Answer |
| ----------- | --------- | ------------ | ---------- | ------------- | ---- | ------ |
|101 | -1 | 11 | 13 | 0 | Should I learn C++ first or Java |  I think C++ is a better Start|
|203 | 101 | 11 | 13 | 0 | Why do you think so! |  Just Google. There is an answer on Quora.|
|205 | 101 | 45 | 13 | 0 | What about python? | |
|211 | -1 | 13 | 11 | 0 | It was nice to chat to you |  For my pleasure Dr Mostafa|
|212 | -1 | 13 | 45 | 0 | Please search archive before asking | |
|300 | 101 | 11 | 13 | 0 | Is it ok to learn Java for OOP? |  Good choice|
|302 | 101 | 11 | 13 | 0 | Why so late in reply? | Not Your Business|
|303 | -1 | 13 | 11 | 1 | How Old Are you Ali | I'm Noha|
|304 | -1 | 13 | 11 | 1 | How Old Are You? | |
-----


## Demo
  * ## Sign Up
    
       <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/answer%20question.png">

  * ## Log In

      <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/log%20in.png">

  * ## Print questions from me

      <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/questions%20from%20me.png">

  * ## Print questions to me

      <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/questions%20to%20me.png">    

  * ## Ask question
    <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/ask%20question.png"> 

  * ## List of Users
    <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/list%20users.png"> 
  * ## Feed
    <img src="https://github.com/EslamAbdelwahid/AskMeSystem/blob/master/images/feed.png">
      
       


    
