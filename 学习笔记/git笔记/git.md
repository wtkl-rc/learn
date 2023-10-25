## git log

## git  reset --hard

回退版本

reset参数是重置命令

--hard是重置代码仓库版本

## git status

## git add、git commit -m 



## git branch，git checkout创建,查看一个分支

使用git checkout -b参数来创建一个分支，创建完成分支后会自动切换过去

git branch -a，git branch -vv查看分支     

git checkout --file     git checkout来切换

## git merge合并分支

当我们新建分支并做完工作之后，想要把分支提交至master，只需要切换到master仓库，并执行git merge 分支名就可以了



操作：

用git checkout -b "math"    创建math分支

在分支里面git add . 文件并  git commit -m "add math"提交

切换回main分支 git checkout main 并 git merge "math"合并math分支

再git push



## git branch -D删除本地分支

## git reflog

git reflog可以查看当前版本库的提交历史，凡是对仓库版本进行迭代的都会出现在这个里面，包括你回滚版本都会出现在这个历史中

## git remote add origin关联到远程仓库



## 查看远程仓库  git remote

## git push -u origin master推送到远程仓库

push：将本地仓库与远程仓库合并

-u：将本地仓库分支与远程仓库分支一起合并，就是说将master的分支也提交上去，这样你就可以在远程仓库上看到你在本地仓库的master中创建了多少分支，不加这个参数只将当前的master与远程的合并，没有分支的历史记录，也不能切换分支

origin：远程仓库的意思，如果这个仓库是远程的那么必须使用这个选项

master：提交本地matser分支仓库

## git将远程仓库关联到本地和拉取指定分支、切换远程分支：git clone

git clone ＋远程仓库ssh+文件夹

## git抓取远程所有分支：git fetch

可以使用git fetch把远程全部分支拉取下来，同时也包括这些分支的仓库版本，log日志等，这个操作不会进行合并。

## 拉取git pull 

拉取指令就是将远端仓库的修改拉到本地自动进行合并。

## 解决合并冲突

vi test01.txt进去之后删除

退出     esc  + ：wq

## idea中使用git

打开设置搜索git，然后按测试

在码云上创建新的仓库

在idea中导入.gitignore

点击vcs然后将文件夹初始化为仓库

连接远程仓库将url复制进去，push

可以clone

有冲突直接pull再删除，然后再push







git使用教程

1.git add 添加到缓存区

2.git commit  -m “sdf”  把文件提交到版本库，并填写备注

3.git push 



