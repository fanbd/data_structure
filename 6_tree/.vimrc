syntax on
imap jj <Esc> 

"显示行号
set number

" 统一缩进为4
set softtabstop=4
set shiftwidth=4

"c/c++  
:set cin	
:set ts=4

inoremap <C-h> <Left>
inoremap <C-j> <Down>
inoremap <C-k> <Up>
inoremap <C-l> <Right>

set encoding=UTF-8
set langmenu=zh_CN.UTF-8
language message zh_CN.UTF-8
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1
set fileencoding=utf-8

"代码补全 
set completeopt=menu 


set nocompatible              " be iMproved, required
filetype off                  " required

"set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

"let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
"Plugin 'scrooloose/nerdtree'
Plugin 'davidhalter/jedi-vim'
"Plugin 'Yggdroot/indentLine'
Plugin 'Valloric/YouCompleteMe'
Plugin 'Raimondi/delimitMate'
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on

"neocomplache config
let g:neocomplcache_enable_at_startup = 1
let g:neocomplcache_force_overwrite_completefunc = 1
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'       "配置全局路径
let g:ycm_confirm_extra_conf=0   "每次直接加载该文件，不提示是否要加载

filetype plugin on
let g:pydiction_location = '~/.vim/tools/pydiction/complete-dict'

