# Data-Structure-Project

XML (Extensible Markup Language) is one of the most famous formats for storing and sharing 
information among different devices. Some text editors such as Sublime Text are able to parse 
such files and do some basic operations. In this project, we work on developing a GUI(Graphical User Interface) based program to parse and visualize an XML file using qt. 
In our system the XML file will represent users in a social network
Each user has id (unique), name, list of posts, list of followers.
Each post has text and list of topics.
we used opp concept to represent xml using classes

                                     
                                     ## What does our software do ##
                                     
1)Checking the XML consistency and correct it
2)Formatting (Prettifying) the XML
![image](https://user-images.githubusercontent.com/105251955/216641375-a427a472-653e-4d25-9095-a764c1356690.png)
3) Converting XML to JSON  
![image](https://user-images.githubusercontent.com/105251955/216641471-52f03ceb-0837-4a24-8e14-b53558b90fb1.png)
4) Compressing & decompressing the data in the XML/JSON file
![image](https://user-images.githubusercontent.com/105251955/216641181-3f37e0d9-7689-42a8-ad77-7bcd7ef6d97c.png)
5) Minifying (This feature should aim at decreasing the size of an XML file (compressing it) by deleting the whitespaces and indentations) 
![image](https://user-images.githubusercontent.com/105251955/216641560-b3f4f4f2-c818-42f9-97c7-999212bac5ad.png)
6) Post search: given a specific word or topic, get the posts where this word or topic was mentioned
![image](https://user-images.githubusercontent.com/105251955/216641744-40722f9a-fc85-432b-a148-ea7d86cb5ac1.png)
7) Network analysis: by representing the network using the graph data structure, we can extract some important data:
- who is the most influencer user (has the most followers)
![image](https://user-images.githubusercontent.com/105251955/216641821-efd38e1a-489a-4a7b-8d51-5edd5945861b.png)
- who is the most active user (connected to lots of users)
![image](https://user-images.githubusercontent.com/105251955/216641871-b2cf76b1-5787-43fc-bb0b-9f8a3ae2cf9d.png)
- the mutual followers between 2 users
![image](https://user-images.githubusercontent.com/105251955/216641920-deff66d9-792d-4c67-bb98-c55e24aa114f.png)
- for each user, suggest a list of users to follow (the followers of his followers) 
![image](https://user-images.githubusercontent.com/105251955/216641977-19de1104-7fbb-4ac8-a953-020ddbf8446b.png)

link for our sofware ==>https://drive.google.com/drive/folders/164RH1VqxBMOjUcySkng4DRuqBXzh3loI
