#! /usr/bin/env python
# -*- coding: iso-8859-15  -*-

"""Tools for automatic generation of some nt2 header files
"""

import os
from file_utils   import write, exist
from nt2_base     import Nt2
from nt2_env      import nt2_dir
from re_list      import sub_if_match_list
from banner       import Banner
from headerguards import Guard
from mylogging    import Mylogging

class Headers(Banner,Guard) :
    """create nt2 guards for an include file
    to be written subsequentely
    given path name and
     (facultative)
    extension
    inner list of lines
    banner text
    guard begin and guard end
    
    - path is the path to the file from a selected directory (nt2)
      as nt2/toolbox/my_funcs/function/ 
    - name is the file name with no extension
    - extension may not include the .
    '.hpp' is the default file name extension

    Default usage is h=Headers(path, name)"""
    
    inner_text = [
        "",
        "//<include> please don't modify between these tags",
        "//<\include>",
        ""
        ]
  
    def __init__(self, path, name,
                 ext = '.hpp',
                 inner = None,
                 banner = None,
                 guard_begin = None,
                 guard_end = None,
                 year = None,
                 comment ='//',
                 fill = None
                 ) :
        Banner.__init__(self, year, banner,comment=comment)
        Guard.__init__(self,path,name,ext,guard_begin,guard_end)
        self.__inner = Headers.inner_text if (inner is None) else inner
        self.__comment = comment
        self.__fill = comment[0] if fill == None else fill
        
    def __str__(self) :
        return '\n'.join(self.get_banner()+
                         self.get_guard_begin()+
                         self.__inner+
                         self.get_guard_end())
        
    def write_header(self,path=None,check=True,flag=None):
#        print "self.total %s"%self.get_total_path()
#        print "path %s"%path

        path2headerfile = os.path.join(nt2_dir() if path is None else path,self.get_total_path())
#        print "path2headerfile %s " % path2headerfile
        if (flag is None) or (flag == 'full') :
            l = self.get_banner()+self.get_guard_begin()+self.__inner+self.get_guard_end()
        elif flag == 'inner' :
            l = self.__inner
        elif flag == 'banner+inner' :
            l = self.get_banner()+self.__inner
        else :
            print "unexpected *** flag : %s " %flag
            raise SystemExit
        if len(self.__fill)==1 :
            l=sub_if_match_list(" @"+self.__comment, "@", self.__fill, l)
        
        self.logger.info( "header written to:\n %s\n" % path2headerfile)
        write(path2headerfile,l,check)

    def write_header2(self,path,check=True,flag=None):
        if (flag is None) or (flag == 'full') :
            l = self.get_banner()+self.get_guard_begin()+self.__inner+self.get_guard_end()
        elif flag == 'inner' :
            l = self.__inner
        elif flag == 'banner+inner' :
            l = self.get_banner()+self.__inner
        else :
            print "unexpected flag : %s " %flag
            raise SystemExit
        if len(self.__fill)==1 :
            l=sub_if_match_list(" @"+self.__comment, "@", self.__fill, l)
        write(path,l,check)
    
if __name__ == "__main__":
    Mylogging.set_level('INFO')
    name = "zuttique"
    path = "./"
    inner_text = [
        "//<INCLUDE> PLEASE DON'T MODIFY BETWEEN THESE TAGS",
        "//<\INCLUDE>",
        ]
    h = Headers(path,name,inner=inner_text,ext='.txt',comment="##")
    print h
    h.write_header(flag='banner+inner')  



