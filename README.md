## S&F Folder Structure
Here is an example how to structure the repositories.
```
application
└─── README.md
|
│   Goal: Algorithm is independent. Can be tested in different scenarios regressively.
└─── app/ (Application folder. Where the necessary libaries, exe, guide.md will be present.)
│    └─── README.md
|    |
│    └─── standalone/ (recomend: GUI communication with algorithm and not hard function call! console, GUI based .exe )
│    |    └─── README.md
│    |    └─── ...
|    |
│    └─── network/ (browser based, i.e. UI/user interface/GUI is seperated from algorithm. It provides communication protocol.)
|    |    └─── README.md
|    |    └─── ...
|    |
│    └─── demodata/ (it is for demonstration)
|         └─── README.md
|         └─── ...
|
└─── code/ (Contains the developed code)
│    └─── README.md
|    |
│    └─── modules/ (core algorithm of an application)
│    |    └─── README.md
│    |    |
│    |    └─── moduleA/
│    |    |    └─── README.md
│    |    |    └─── ...
│    |    |
│    |    └─── moduleB/
│    |         └─── README.md
│    |         └─── ...
│    |      
│    └─── views/ (console / GUI)
│         └─── README.md
│         └─── ...
|
└───docs/
│    └─── README.md
|    |
│    └─── admin/ (administraction, meeting minutes, ... )
│    |     └─── README.md
│    |     └─── ...
|    |
│    └─── design/ ( design of the application and not the research. Should be updated as we update the code)
│    |     └─── README.md
│    |     └─── ...
|    |
│    └─── report/ ( test report of current application, which reflect the current application stauts: accuracy, performance, etc)
│    |     └─── README.md
│    |     └─── ...
|    |
│    └─── research/ ( research documents, literature study, PoC ).
│    |     └─── README.md
│    |     |
|    |     └─── start-of-art/ (of app, research finding that our application is making use of. i.e. summary of the literature study.)
│    |     |    └─── README.md
│    |     |    └─── ...
│    |     |   
|    |     └─── external document/ (link. Each paper summary)
│    |          └─── README.md
│    |          └─── ...
|    |
│    └─── roadmap ( roadmap, milestone, working packages )
│          └─── README.md
│          └─── ...
|     
└─── ext/ (folder where to place external libs and dependencies)
│    └─── README.md
|    |
│    └─── libs/
│    |    └─── README.md
│    │    └─── ...
│    │   
│    └─── poc/
│         └─── README.md
│         └─── ...
|     
└─── test/ (folder where to place test scripts and data)
     └─── README.md
     |
     └─── unit/
     |    └─── README.md
     │    └─── ...
     │   
     └─── integration/
     │    └─── README.md
     │    └─── ...
     │   
     └─── data/ (Static data: less 20 MB in github, else link to LRZ. Recommend: To have data repo e..g LRZ, X-Driver)
          └─── README.md
          └─── ...
```
