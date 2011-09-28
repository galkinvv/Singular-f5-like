;; emacs edit mode for this file is -*- Emacs-Lisp -*-
;; $Id: fold-docu.el 12231 2009-11-02 10:12:22Z hannes $

;;{{{ docu
;;
;; fold-docu.el - fold all documentation foldings in a file.
;;
;; To unfold all documentation, call fold-open-buffer.
;;
;;}}}

(require 'folding)

(defun fold-docu ()
  "Fold all documentation foldings in a file."
  (interactive)
  (goto-char (point-min))
  (save-excursion
    (while (re-search-forward "{{{ .*docu$" nil t)
      (fold-hide))))

(provide 'fold-docu)
