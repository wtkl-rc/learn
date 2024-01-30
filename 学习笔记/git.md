# git

版本库就是.git文件夹、工作区就是跟.git同目录的文件夹、.git里面的index文件就是暂存区

# 基本操作

## git init

本地初始化仓库

## git log

查看日志跟版本

## git  reset 

可以加文件名，把暂存的文件变为未被暂存和git add相反

## git  reset --hard

使用git log查看版本信息

然后gti reset --hard + 版本信息

## git status

查看文件的状态：未被跟踪、已被跟踪（修改、未修改、暂存）

## git add

add把文件放进暂存区

## git commit -m 

git commit -m把文件提交到本地仓库，-m是message

## git reflog

git reflog可以查看当前版本库的提交历史，凡是对仓库版本进行迭代的都会出现在这个里面，包括你回滚版本都会出现在这个历史中

# 分支

两个分支互不影响，可以有不相同的文件

## git branch

查看分支

git branch +  branchname 创建分支

git branch -r 列出远程仓库分支

git branch -a 查看所有仓库分支

git branch -vv查看分支     

## git checkout

git checkout + 分支名称 切换分支

git checkout -b参数来创建一个分支，创建完成分支后会自动切换过去  

git checkout --file  

## git push origin b1

将本地分支提交到本地仓库

推送本地分支到远程仓库

## git merge

当我们新建分支并做完工作之后，想要把分支提交至master，只需要切换到master仓库，并执行git merge 分支名就可以了

git merge + branchname

## git branch -D

删除本地分支

# 远程仓库

## git remote

查看远程仓库 	加参数-v可查看具体的地址

## git  remote add

git remote add origin + url 本地初始化的仓库没有关联任何远程仓库使用这个命令**添加远程仓库**

## git push

git push remote-name branch 推送到远程仓库  例如： git push origin master 

## git push -u origin master

推送到远程仓库

-u：将本地仓库分支与远程仓库分支一起合并，就是说将master的分支也提交上去，这样你就可以在远程仓库上看到你在本地仓库的master中创建了多少分支，不加这个参数只将当前的master与远程的合并，没有分支的历史记录，也不能切换分支

master：提交本地matser分支仓库

## git clone

git clone ＋远程仓库ssh+文件夹git将远程仓库关联到本地和拉取指定分支、切换远程分支

## git fetch

git抓取远程所有分支：

可以使用git fetch把远程全部分支拉取下来，同时也包括这些分支的仓库版本，log日志等，这个操作不会进行合并。

## git pull 

// 先执行
git pull origin master --allow-unrelated-histories

允许无关历史 --allow-unrelated-histories 在原来的命令加上，就是本地初始化的仓库和远程的不一样，有不同的历史，加上这个就可以拉取

拉取指令就是将远端仓库的修改拉到本地自动进行合并。

## 解决合并冲突

在b1和master分支里面修改同一个文件，合并的时候会发生冲突，则需要我们手动进到文件里面修改成自己想要的，然后再提交到远程仓库

## git tag 标签

git tag 查看全部标签

git tag + name 新建标签

git push origin + tagname推送

git checkout -b branchname tagname 检出标签   需要新建一个分支，所以branchname就是新建标签名字



