"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"
" Based on https://github.com/yangyangwithgnu/use_vim_as_ide
"
" Pre-Install:
" sudo apt-get install git
" sudo apt-get install exuberant-ctags
" sudo apt-get install silversearcher-ag
"
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 常用快捷键
"

" ^ - 跳至行首

" $ - 跳至行尾

" % - 在结对符之间跳转

" dd - 删除一行

" ndd - 删除以当前行开始的n行

" g] - 查找标签

" ctrl-t - 返回标签栈之前的位置

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 自定义快捷键
"

" 定义快捷键的前缀，即<Leader>
let mapleader=";"

" 依次遍历子窗口
nnoremap <Leader>wn <C-W><C-W>

" 跳转至右方的窗口
nnoremap <Leader>wl <C-W>l

" 跳转至左方的窗口
nnoremap <Leader>wh <C-W>h

" 跳转至上方的子窗口
nnoremap <Leader>wk <C-W>k

" 跳转至下方的子窗口
nnoremap <Leader>wj <C-W>j

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 基础配置
"

" 让配置变更立即生效
autocmd BufWritePost $MYVIMRC source $MYVIMRC

" 开启实时搜索功能
set incsearch

" 搜索时大小写不敏感
set ignorecase

" 关闭兼容模式
set nocompatible

" vim 自身命令行模式智能补全
set wildmenu

" 开启文件类型侦测

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<
filetype on

" 根据侦测到的不同类型加载对应的插件
filetype plugin on

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: Vundle
"
" Refer to: https://github.com/VundleVim/Vundle.vim
"

set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'altercation/vim-colors-solarized'
Plugin 'tomasr/molokai'
Plugin 'vim-scripts/phd'
Plugin 'Lokaltog/vim-powerline'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'kshenoy/vim-signature'
Plugin 'vim-scripts/BOOKMARKS--Mark-and-Highlight-Full-Lines'
Plugin 'majutsushi/tagbar'
Plugin 'vim-scripts/indexer.tar.gz'
Plugin 'vim-scripts/DfrankUtil'
Plugin 'vim-scripts/vimprj'
Plugin 'dyng/ctrlsf.vim'
Plugin 'terryma/vim-multiple-cursors'
Plugin 'scrooloose/nerdcommenter'
Plugin 'scrooloose/nerdtree'
Plugin 'fholgado/minibufexpl.vim'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 界面配置
"

" 配色方案
set background=dark
"colorscheme solarized
colorscheme molokai
"colorscheme phd

" 禁止光标闪烁
set gcr=a:block-blinkon0

" 禁止显示滚动条
set guioptions-=l
set guioptions-=L
set guioptions-=r
set guioptions-=R

" 禁止显示菜单和工具条
set guioptions-=m
set guioptions-=T

" 总是显示状态栏
set laststatus=2

" 显示光标当前位置
set ruler

" 开启行号显示
set number

" 高亮显示当前行/列
set cursorline
set cursorcolumn

" 高亮显示搜索结果
set hlsearch

" 禁止折行
set nowrap

" 设置状态栏主题风格
let g:Powerline_colorscheme='solarized256'

" 设置状态栏显示文件路径
let g:Powerline_stl_path_style='relative'

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 代码配置
"

" 开启语法高亮功能
syntax enable

" 允许用指定语法高亮配色方案替换默认方案
syntax on

" 自适应不同语言的智能缩进
filetype indent on

" 将制表符扩展为空格
set expandtab

" 设置编辑时制表符占用空格数
set tabstop=4

" 设置格式化时制表符占用空格数
set shiftwidth=4

" 让 vim 把连续数量的空格视为一个制表符
set softtabstop=4

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: vim-cpp-enhanced-highlight
"

" 添加高亮关键字
"syntax keyword cppSTLtype initializer_list

" 高亮 POSIX 函数
let g:cpp_posix_standard = 1

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: vim-indent-guides
"

" 随 vim 自启动
let g:indent_guides_enable_on_vim_startup=1

" 从第二层开始可视化显示缩进
let g:indent_guides_start_level=2

" 色块宽度
let g:indent_guides_guide_size=1

" 默认按键映射 <Leader>ig
"nmap <silent> <Leader>ig <Plug>IndentGuidesToggle
"nmap <silent> <Leader>ie <Plug>IndentGuidesEnable
"nmap <silent> <Leader>id <Plug>IndentGuidesDisable

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: vim-signature
"

" 自定义快捷键
"
" PlaceNextMark
" PurgeMarksAtLine
" PurgeMarks
" GotoNextSpotByPos
" GotoPrevSpotByPos
" ListLocalMarks
"
let g:SignatureMap = {
        \ 'Leader'             :  "m",
        \ 'PlaceNextMark'      :  "m,",
        \ 'ToggleMarkAtLine'   :  "mt",
        \ 'PurgeMarksAtLine'   :  "m.",
        \ 'DeleteMark'         :  "dm",
        \ 'PurgeMarks'         :  "md",
        \ 'PurgeMarkers'       :  "m<BS>",
        \ 'GotoNextLineAlpha'  :  "']",
        \ 'GotoPrevLineAlpha'  :  "'[",
        \ 'GotoNextSpotAlpha'  :  "`]",
        \ 'GotoPrevSpotAlpha'  :  "`[",
        \ 'GotoNextLineByPos'  :  "]'",
        \ 'GotoPrevLineByPos'  :  "['",
        \ 'GotoNextSpotByPos'  :  "mn",
        \ 'GotoPrevSpotByPos'  :  "mp",
        \ 'GotoNextMarker'     :  "[+",
        \ 'GotoPrevMarker'     :  "[-",
        \ 'GotoNextMarkerAny'  :  "]=",
        \ 'GotoPrevMarkerAny'  :  "[=",
        \ 'ListLocalMarks'     :  "m/",
        \ 'ListLocalMarkers'   :  "m?"
        \ }

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: tagBar
"

" 默认打开tagbar
"autocmd VimEnter * nested :TagbarOpen

" 设置 tagbar 子窗口的位置出现在主编辑区的左边
let tagbar_left=1

" 设置显示／隐藏标签列表子窗口的快捷键
nnoremap <Leader>tb :TagbarToggle<CR>

" 设置标签子窗口的宽度
let tagbar_width=64

" tagbar 子窗口中不显示冗余帮助信息
let g:tagbar_compact=1

" 设置标签排序方式
let g:tagbar_sort = 0

" 设置 ctags 对哪些代码标识符生成标签
let g:tagbar_type_cpp = {
    \ 'kinds' : [
        \ 'c:classes:0:1',
        \ 'd:macros:0:1',
        \ 'e:enumerators:0:1',
        \ 'f:functions:0:1',
        \ 'g:enumeration:0:1',
        \ 'm:members:0:1',
        \ 'n:namespaces:0:1',
        \ 'p:functions_prototypes:0:1',
        \ 's:structs:0:1',
        \ 't:typedefs:0:1',
        \ 'u:unions:0:1',
        \ 'v:global:0:1',
        \ 'x:external:0:1'
    \ ],
    \ 'sro'        : '::',
    \ 'kind2scope' : {
        \ 'g' : 'enum',
        \ 'n' : 'namespace',
        \ 'c' : 'class',
        \ 's' : 'struct',
        \ 'u' : 'union'
    \ },
    \ 'scope2kind' : {
        \ 'enum'      : 'g',
        \ 'namespace' : 'n',
        \ 'class'     : 'c',
        \ 'struct'    : 's',
        \ 'union'     : 'u'
    \ }
\ }

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: nerdcommenter
"

" <leader>cc，注释当前选中文本.
" <leader>cu，取消选中文本块的注释.

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: nerdtree
"

" 使用 NERDTree 插件查看工程文件
nmap <Leader>fl :NERDTreeToggle<CR>

" 设置NERDTree子窗口宽度
let NERDTreeWinSize=32

" 设置NERDTree子窗口位置
let NERDTreeWinPos="left"

" 显示隐藏文件
let NERDTreeShowHidden=1

" NERDTree 子窗口中不显示冗余帮助信息
let NERDTreeMinimalUI=1

" 删除文件时自动删除文件对应 buffer
let NERDTreeAutoDeleteBuffer=1

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: minibufexpl.vim
"

" 显示/隐藏 MiniBufExplorer 窗口
map <Leader>bl :MBEToggle<cr>

" 启动时显示 buffer
let g:miniBufExplBuffersNeeded = 1

" buffer 切换快捷键
let g:miniBufExplMapCTabSwitchBufs = 1
noremap <leader>bn :MBEbn<CR>
noremap <leader>bp :MBEbp<CR>

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: indexer.tar.gz
"

" 设置插件 indexer 调用 ctags 的参数
" 默认 --c++-kinds=+p+l，重新设置为 --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v
" 默认 --fields=+iaS 改为 --fields=+iaSl
let g:indexer_ctagsCommandLineOptions="--c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: ctrlsf
"

" 插件在工程内全局查找光标所在关键字
nnoremap <Leader>sp :CtrlSF<CR>

let g:ctrlsf_default_view_mode = 'compact'

let g:ctrlsf_indent = 2

let g:ctrlsf_selected_line_hl = 'op'

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<

" >>>>>>>>>>>>>>>>>>>>>>>>>>>>
"
" 插件配置: vim-multiple-cursors
"

let g:NERDSpaceDelims = 1

let g:NERDCompactSexyComs = 1

let g:NERDTrimTrailingWhitespace = 1

" <<<<<<<<<<<<<<<<<<<<<<<<<<<<
