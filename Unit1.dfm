object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 308
  ClientWidth = 304
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 89
    Top = 8
    Width = 59
    Height = 13
    Caption = 'enter length'
  end
  object Button1: TButton
    Left = 8
    Top = 24
    Width = 75
    Height = 25
    Caption = 'create array'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 55
    Width = 75
    Height = 25
    Caption = 'show array'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 89
    Top = 26
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object ListBox1: TListBox
    Left = 89
    Top = 55
    Width = 121
    Height = 218
    ItemHeight = 13
    TabOrder = 3
  end
  object Button3: TButton
    Left = 216
    Top = 24
    Width = 75
    Height = 25
    Caption = 'bubble sort'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 216
    Top = 55
    Width = 75
    Height = 25
    Caption = 'selection sort'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 216
    Top = 86
    Width = 75
    Height = 25
    Caption = 'bubble 1'
    TabOrder = 6
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 216
    Top = 120
    Width = 75
    Height = 25
    Caption = 'bubble 2'
    TabOrder = 7
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 216
    Top = 151
    Width = 75
    Height = 25
    Caption = 'insertion '
    TabOrder = 8
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 216
    Top = 184
    Width = 75
    Height = 25
    Caption = 'merge sort'
    TabOrder = 9
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 216
    Top = 215
    Width = 75
    Height = 25
    Caption = 'Quick sort'
    TabOrder = 10
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 216
    Top = 246
    Width = 75
    Height = 25
    Caption = 'heap sort'
    TabOrder = 11
    OnClick = Button10Click
  end
end
