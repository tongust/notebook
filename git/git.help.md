# Create Branch
## Create local branch
Firstly, create branch locally,
```
git branch <branch-new>
```
or create and checkout it by
```
git checkout -b <branch-new>
```
## Create romote branch based on local branch
```
git push <remote-name> <branch-new>
```
Where \<remote-name\> is typically origin, the name which git gives to the remote you cloned from. Your colleagues would then just pull that branch, and it's automatically created locally.

## Push
The current branch build-second-index has no upstream branch.
To push the current branch and set the remote as upstream, use
```shell
git push --set-upstream origin build-second-index
```
# Syncing to a fork
Sync a fork of a repository to keep it up-to-date with the upstream repository.

> upstream repository: the repo of owner.
> origin repository: the repo which you self own.

## Before syncing: configuring a remote for a fork
- list the current remote repository:
> git remote -v

- Specify a new remote upstream repo:
> git remote add upstream https://github.com/ORIGINAL\_OWNER/ORIGINAL\_REPOSITORY.git

## git fetch upstream

# Configure the Git Server
## Host
### Make sure that there exits (host) id\_rsa file
If it does not, run in shell
```{shell}
ssh-keygen -t rsa -C "youremali@xxx.xx"
# Accept any default option 
```
Then, you will find two file:
- id\_rsa: private key
- id\_rsa.pub: public key

Next, append the content in id\_rsa.pub into the *authorized\_keys* file.

### Push
- git push -u origin mater : For the first time
- git push: For second time : For the second time

## Remote
### Creat git user
```{shell}
sudo git adduser git
```
### Create key
Same with *Host*'s configuration, expect that you have to create */home/git/.ssh/authorized\_keys* file.

### Deny any ssh-login
**sudo vi /etc/passwd**
Change
```
git:x:1001:1001:,,,:/home/git:/bin/bash
```
to
```
git:x:1001:1001:,,,:/home/git:/bin/bash
```
## Init a project
Create a git in remote server.
>cd /srv/

>sudo git init --bare sample.git

>sudo chown -R git:git sample.git

# Keeping a fork up to date
## 1. Clone your fork:

>    git clone git@github.com:YOUR-USERNAME/YOUR-FORKED-REPO.git



## 2. Add remote from original repository in your forked repository: 

>    cd into/cloned/fork-repo
>    git remote add upstream git@github.com:lennylxx/ipv6-hosts.git
>    git fetch upstream


## 3. Updating your fork from original repo to keep up with their changes:

>    git pull upstream master


# ['Merge' specific files from Git branches](https://stackoverflow.com/questions/18115411/how-to-merge-specific-files-from-git-branches)
```
$ git branch
master
*branch1
branch2
```
Aussming you want to merge *file.cpp* in branch2 to *file.cpp* in branch1 (in current branch).
```
#$git checkout branch1
$ git checkout --patch branch2 file.cpp
```
To have full control do an interactive merge using *--patch* switch:
```
y - stage this hunk
n - do not stage this hunk
q - quit; do not stage this hunk nor any of the remaining ones
a - stage this hunk and all later hunks in the file
d - do not stage this hunk nor any of the later hunks in the file
g - select a hunk to go to
/ - search for a hunk matching the given regex
j - leave this hunk undecided, see next undecided hunk
J - leave this hunk undecided, see next hunk
k - leave this hunk undecided, see previous undecided hunk
K - leave this hunk undecided, see previous hunk
s - split the current hunk into smaller hunks
e - manually edit the current hunk
? - print help
```
# [Show changes as Git Gui](https://stackoverflow.com/questions/1587846/how-do-i-show-the-changes-which-have-been-staged)
![A simple graphic](./figures/graphic-git-diff.png)
## git diff
Shows the changes between the working directory and the index. This shows what has been changed, but is not staged for a commit.

## git diff --cached
Shows the changes between the index and the *HEAD* (which is the last commit on this branch). This shows what has been added to the index and staged for a commit.

## git diff *HEAD*
Shows all the changes between the working directory and *HEAD* (which includes changes in the index). This shows all the changes since the last commit, whether or not they have been staged for commit or not.

# Manage branchs (not conflic, no, no, no)

# git pull vs git pull --rebase (not conflic)
modifyed by current branch
modifyed again 2
modifyed again
modified again by left-left-right-right-left-left-left-right
