CREATE trigger id_Insert_additionalinfo
after insert ON Enrollees
FOR each row
begin
UPDATE Enrollees
SET id_additionalInfo = (SELECT id_additionalInfo FROM AdditionalInfo WHERE additional_info = NEW.additional_info_combox)
WHERE id_enrollees = NEW.id_enrollees;
end;
