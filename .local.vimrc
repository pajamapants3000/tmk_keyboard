"
" .local.vimrc for tmk_keyboard
"

" set root to root of source tree
let root=$HOME."/repo/tmk_keyboard"

" set search path to include all header file paths
exe "set path+=" . "/opt/avr/avr/include"
exe "set path+=" . root ."/tmk_core/common"

" whitelist YouCompleteMe configuration for this repository
let g:ycm_extra_conf_globlist=[root."/.ycm_extra_conf.py"]

