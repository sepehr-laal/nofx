ofxNode
=======

OpenFrameworks wrapped as a NodeJS module and beyond!
-----------------------------------------------------


----------


Before opening the project make sure you have following variables (texts in bold) defined on your environment. The final folder structure for each environment variable should be as shown (assuming each project is cloned by Git):

 - **OFXNODE_NAN**
  - nan
     - .git
     - ...
 - **OFXNODE_NODE**
  - node
     - .git
     - ...
 - **OFXNODE_OF**
  - openFrameworks
     - .git
     - ...

***FOR WINDOWS ONLY:*** Also make sure before building all projects, you set the flag for **ALL** projects to **/MD** or **/MDd** in Visual Studio. This violates v8's default configuration but its inevitable for now.


----------

Build instructions (Windows):
-----------------------------
**After defining environement variables**, you may start building ofxNode. The first step in building ofxNode, is building Node (duh!). You should build Node **before** anything else. ofxNode expects to see Node's libraries and headers before it can compile. For compiling Node:

 1. Navigate to %OFXNODE_NODE%
 2. run `vcbuild.bat nobuild`
 3. open up `node.sln` in a **Visual Studio that matches the version of Visual Studio your OpenFrameworks clone is using**
 4. Upgrade node projects in visual studio if needed
 5. Change all code generation flags to /MD or /MDd
 6. Build.

The rest of the projects (OpenFrameworks, NaN, and ofxNode) will be built all together by builidng the **ofxNode.sln**.